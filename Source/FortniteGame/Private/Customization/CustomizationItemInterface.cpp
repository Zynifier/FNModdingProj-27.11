// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomizationItemInterface.h"

UAthenaCosmeticItemDefinition* ICustomizationItemInterface::GetCustomizationCosmeticItem() const
{
	return nullptr;
}

USceneComponent* ICustomizationItemInterface::GetCustomizationItemRotatableSceneComponent() const
{
	return nullptr;
}

void ICustomizationItemInterface::ResetCustomizationCosmeticItemAndVariants(UAthenaCosmeticItemDefinition* NewCosmeticItemDefinition, const TArray<FMcpVariantChannelInfo>& InOverrideVariants)
{
}

void ICustomizationItemInterface::SetCustomizationCosmeticItemAndVariants(UAthenaCosmeticItemDefinition* NewCosmeticItemDefinition, const TArray<FMcpVariantChannelInfo>& InOverrideVariants)
{
}
