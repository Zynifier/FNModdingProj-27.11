// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricMeshProvider.h"

void UFabricMeshProviderBase::SetReferenceMesh(const FFabricMeshProviderMeshReference& InMesh)
{
}

void UFabricMeshTreeNode::CopyProperties(const UFabricMeshTreeNode* Other)
{
}

TArray<FFabricMeshInstanceReference> UFabricMeshTreeNode::GenerateMeshInstanceReferences() const
{
	return TArray<FFabricMeshInstanceReference>();
}

void UFabricMeshTreeNode::Reset()
{
}
