#include <Vertex/VertexObject.h>

#include <glad/glad.h>

#include <utility>

namespace ViperGL
{
	VertexObject::VertexObject(std::initializer_list<float> vertices)
		: mVBO(0)
		, mVAO(0)
		, mVertices(std::move(vertices))
	{
		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(*mVertices.begin()), mVertices.begin(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(*mVertices.begin()), nullptr);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexObject::~VertexObject()
	{
		glDeleteVertexArrays(1, &mVAO);
		glDeleteBuffers(1, &mVBO);
	}

	void VertexObject::bind()
	{
		glBindVertexArray(mVAO);
	}
}