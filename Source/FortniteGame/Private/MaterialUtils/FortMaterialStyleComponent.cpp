// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaterialUtils/FortMaterialStyleComponent.h"

const FActiveStyleInfo& UFortMaterialStyleComponent::GetActiveStyleInfo() const
{
	static FActiveStyleInfo Dummy;
	return Dummy;
}

UMaterialInstanceDynamic* UFortMaterialStyleComponent::GetDynamicMaterialInstance() const
{
	return nullptr;
}

void UFortMaterialStyleComponent::RequestStyleChange(const FRequestStyleParams& Request, const EStyleRequestArbitrationPolicy RequestArbitrationPolicy)
{
}
