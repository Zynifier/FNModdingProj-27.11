// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortCreativeSplineModificationComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeSplineModificationComponent::DestroyControlPoints(AActor* DestroyedActor)
{
}

void UFortCreativeSplineModificationComponent::GenerateControlPointsForSpline()
{
}

FSplinePoint UFortCreativeSplineModificationComponent::MakeSplinePoint(const FSplinePoint_Serializable& SerializableSplinePoint)
{
	return FSplinePoint();
}

void UFortCreativeSplineModificationComponent::OnRep_ControlPoints()
{
}

void UFortCreativeSplineModificationComponent::OnRep_SplinePoints_NonSerializable()
{
}

void UFortCreativeSplineModificationComponent::OnSavedSplineDataLoaded(const TArray<FSplinePoint_Serializable>& SavedSplinePoints)
{
}

void UFortCreativeSplineModificationComponent::PopulateSerializedSplineDataFromSpline()
{
}

void UFortCreativeSplineModificationComponent::SaveSplinePointData()
{
}

void UFortCreativeSplineModificationComponent::SetSplinePoints(const TArray<FSplinePoint>& InSplinePoints)
{
}

void UFortCreativeSplineModificationComponent::UpdateEditorPreview(const TArray<FSplinePoint_Serializable>& InSplinePoints)
{
}

void UFortCreativeSplineModificationComponent::UpdateTransientComponentTransforms()
{
}

void UFortCreativeSplineModificationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeSplineModificationComponent, SplinePoints_NonSerializable);
	DOREPLIFETIME(UFortCreativeSplineModificationComponent, ControlPoints);
}
