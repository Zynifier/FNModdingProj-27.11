// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortCreativeResourceNodeComponent.h"

void UFortCreativeResourceNodeComponent::AddInventoryItemWithoutAnimation(AFortPlayerController* InInstigatorController, const FFortItemEntry& ItemDescription)
{
}

void UFortCreativeResourceNodeComponent::ClearAffectedProps()
{
}

TArray<ABuildingSMActor*> UFortCreativeResourceNodeComponent::GetAffectedProps() const
{
	return TArray<ABuildingSMActor*>();
}

EFortResourceType::Type UFortCreativeResourceNodeComponent::GetOriginalResourceType(ABuildingSMActor* InProp) const
{
	return EFortResourceType::Type();
}

int32 UFortCreativeResourceNodeComponent::GetResourcesRemainingOnProp(ABuildingSMActor* InProp) const
{
	return int32();
}

void UFortCreativeResourceNodeComponent::ModifyResourcesRemainingOnAllProps(const int32 InDeltaChange)
{
}

void UFortCreativeResourceNodeComponent::ModifyResourcesRemainingOnProp(ABuildingSMActor* InPropToSet, const int32 InDeltaChange)
{
}

void UFortCreativeResourceNodeComponent::ReportDamagedResourceBuildingOnClient(AFortPlayerController* InInstigatorController, ABuildingSMActor* InBuilding, const EFortResourceType::Type InResourceType, const int32 InResourcesToDistribute, const bool bIsDestroyed, const bool bJustHitWeakspot)
{
}

void UFortCreativeResourceNodeComponent::SetAffectedProps(TArray<ABuildingSMActor*> InAffectedProps)
{
}

void UFortCreativeResourceNodeComponent::SetResourcesRemainingOnAllProps(const int32 InResourcesRemaining)
{
}

void UFortCreativeResourceNodeComponent::SetResourcesRemainingOnProp(ABuildingSMActor* InPropToSet, const int32 InResourcesRemaining)
{
}

void UFortCreativeResourceNodeComponent::SetRestockTimer(ABuildingSMActor* InPropToRestock, const EFortCreativeResourceNodeDepletionMode InDepletionMode, const int32 RestockDelay, const int32 RestockAmount)
{
}
