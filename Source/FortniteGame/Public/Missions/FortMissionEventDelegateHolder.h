// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMissionEventDelegateHolder.generated.h"

class ABuildingContainer;
class ABuildingSMActor;
class AFortPawn;
class AFortPlayerPawn;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnMissionBuildingSMActorHarvestedEvent, ABuildingSMActor*, HarvestedBuilding, AFortPlayerPawn*, HarvesterPawn);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnMissionContainerSearchedEvent, ABuildingContainer*, SearchedContainer, AFortPawn*, SearcherPawn);

UCLASS()
class UFortMissionEventDelegateHolder : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UBuildingSMActorHarvestedDelegateHolder : public UFortMissionEventDelegateHolder
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FOnMissionBuildingSMActorHarvestedEvent OnBuildingSMActorHarvestedDelegate;

};

UCLASS()
class UContainerSearchedDelegateHolder : public UFortMissionEventDelegateHolder
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FOnMissionContainerSearchedEvent OnContainerSearchedDelegate;

};

