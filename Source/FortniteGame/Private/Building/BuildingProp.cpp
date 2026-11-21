// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingProp.h"

float ABuildingProp::BlueprintModifyIncomingDamage_Implementation(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser)
{
	return float();
}

FBox ABuildingProp::BP_GetComponentsBoundingBox_Implementation(bool bNonColliding, bool bIncludeFromChildActors) const
{
	return FBox();
}

void ABuildingProp::BP_GetEyesViewpoint_Implementation(FVector& OutLocation, FRotator& OutRotation) const
{
}

FBox ABuildingProp::GetBoundingBoxWithIgnoredComponents(TArray<UPrimitiveComponent*> IgnoredComponents, const bool bNonColliding, const bool bIncludeFromChildActors) const
{
	return FBox();
}

const FMarkedActorDisplayInfo ABuildingProp::GetMarkerDisplayData_Implementation() const
{
	return FMarkedActorDisplayInfo();
}

const FVector ABuildingProp::GetMarkerPositionOffset_Implementation() const
{
	return FVector();
}

bool ABuildingProp::IsBuildingVolume()
{
	return false;
}

void ABuildingProp::SetAsBuildingVolume(const bool bNewValue)
{
}
