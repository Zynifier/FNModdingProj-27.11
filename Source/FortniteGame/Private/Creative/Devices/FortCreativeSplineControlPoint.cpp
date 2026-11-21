// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Devices/FortCreativeSplineControlPoint.h"
#include "Net/UnrealNetwork.h"

float AFortCreativeSplineControlPoint::GetArriveTangentIntensity_Implementation() const
{
	return float();
}

float AFortCreativeSplineControlPoint::GetLeaveTangentIntensity_Implementation() const
{
	return float();
}

ESplinePointType::Type AFortCreativeSplineControlPoint::GetSplinePointType_Implementation() const
{
	return ESplinePointType::Type();
}

void AFortCreativeSplineControlPoint::OnPropertiesUpdated()
{
}

void AFortCreativeSplineControlPoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativeSplineControlPoint, SplineIndex);
	DOREPLIFETIME(AFortCreativeSplineControlPoint, bInitializedFromOwningSplineProp);
	DOREPLIFETIME(AFortCreativeSplineControlPoint, OwningSplineProp);
	DOREPLIFETIME(AFortCreativeSplineControlPoint, CopiedFrom);
	DOREPLIFETIME(AFortCreativeSplineControlPoint, CopiedFromCut);
}
