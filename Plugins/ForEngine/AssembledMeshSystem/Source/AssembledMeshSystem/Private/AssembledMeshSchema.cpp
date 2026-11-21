// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssembledMeshSchema.h"

#if WITH_EDITOR
TSoftObjectPtr<UCustomizableObjectInstance> UAssembledMeshSchema::GetCustomizableObjectInstance() const
{
	return TSoftObjectPtr<UCustomizableObjectInstance>();
}
#endif

#if WITH_EDITOR
void UAssembledMeshSchema::SetCustomizableObjectInstance(TSoftObjectPtr<UCustomizableObjectInstance> InCustomizableObjectInstance)
{
}
#endif
