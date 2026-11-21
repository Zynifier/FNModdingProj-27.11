// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeItemVariantNotifierComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeItemVariantNotifierComponent::BindToItemVariant(const FItemVariantHandle& VariantHandle)
{
}

int32 UFortCreativeItemVariantNotifierComponent::GetNumBoundItemVariants() const
{
	return int32();
}

const FItemVariantHandle& UFortCreativeItemVariantNotifierComponent::GetReplicatedWeaponVariantHandle() const
{
	static FItemVariantHandle Dummy;
	return Dummy;
}

bool UFortCreativeItemVariantNotifierComponent::GetTemplateObjects(TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled) const
{
	return false;
}

bool UFortCreativeItemVariantNotifierComponent::GetTemplateObjectsByIndex(int32 VariantIndex, TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled) const
{
	return false;
}

bool UFortCreativeItemVariantNotifierComponent::GetTemplateObjectsByVariant(const FItemVariantHandle& VariantHandle, TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled) const
{
	return false;
}

void UFortCreativeItemVariantNotifierComponent::UnbindFromAllItemVariants()
{
}

void UFortCreativeItemVariantNotifierComponent::UnbindFromItemVariant(const FItemVariantHandle& VariantHandle)
{
}

void UFortCreativeItemVariantNotifierComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeItemVariantNotifierComponent, WeaponVariantHandle);
}
