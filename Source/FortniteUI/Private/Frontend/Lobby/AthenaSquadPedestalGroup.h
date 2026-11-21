// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortSubGameTypes.h"
#include "AthenaSquadPedestalGroup.generated.h"

class AFortTeamMemberPedestal;
class USceneComponent;

UCLASS(Abstract)
class AAthenaSquadPedestalGroup : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaSquadPedestalGroup")
	ESubGame UsedSubgame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadPedestalGroup", meta=(AllowPrivateAccess="TRUE"))
	int32 MonitoredSquadIdx;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSquadPedestalGroup", meta=(AllowPrivateAccess="TRUE"))
	TArray<TObjectPtr<AFortTeamMemberPedestal>> MemberPedestals;

	UPROPERTY(VisibleAnywhere, Export, Category="AthenaSquadPedestalGroup", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> PedestalChildrenRoot;

};

