#include <vcg/complex/complex.h>
#include <vcg/complex/algorithms/update/topology.h>
#include <vcg/complex/algorithms/update/flag.h>
#include <wrap/io_trimesh/import_off.h>
#include <wrap/io_trimesh/import_obj.h>
#include <iostream>
class MyVertex;
class MyEdge;
class MyFace;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>::AsVertexType,
                                           vcg::Use<MyEdge>::AsEdgeType,
                                           vcg::Use<MyFace>::AsFaceType>
{
};

class MyVertex : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags>
{
};
class MyFace : public vcg::Face<MyUsedTypes, vcg::face::VFAdj, vcg::face::VertexRef, vcg::face::BitFlags>
{
};
class MyEdge : public vcg::Edge<MyUsedTypes>
{
};

class MyMesh : public vcg::tri::TriMesh<std::vector<MyVertex>, std::vector<MyFace>, std::vector<MyEdge>>
{
};

class MyVertex0 : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::BitFlags>
{
};
class MyVertex1 : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags>
{
};
class MyVertex2 : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Color4b, vcg::vertex::CurvatureDirf,
                                     vcg::vertex::Qualityf, vcg::vertex::Normal3f, vcg::vertex::BitFlags>
{
};

int main(int argc, char **argv)
{
    MyMesh m;

    vcg::tri::io::ImporterOBJ<MyMesh>::Info oifo;
    vcg::tri::io::ImporterOBJ<MyMesh>::Open(m, "E:/datas/obj/plane.obj", oifo);

    vcg::tri::UpdateFlags<MyMesh>::VertexBorderFromNone(m);
    

    auto begin = m.vert.begin();
    for (size_t i = 0; i < m.vert.size(); i++)
    {
        std::string isB = m.vert[i].IsB() ? "Yes" : "No";
        std::cout << "vert " << i << " = (" << m.vert[i].P().X() << ", " << m.vert[i].P().Y() << ", " << m.vert[i].P().Z() << ")" << std::endl;
        std::cout << "Is vert border ? " << isB << std::endl;
    }
    
    vcg::tri::RequirePerVertexNormal(m);
    vcg::tri::UpdateNormal<MyMesh>::PerVertexNormalized(m);
    printf("Input mesh  vn:%i fn:%i\n", m.VN(), m.FN());
    printf("Mesh has %i vert and %i faces\n", m.VN(), m.FN());

    return 0;
}
