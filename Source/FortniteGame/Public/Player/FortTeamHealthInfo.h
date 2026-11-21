// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Player/FortTeamPrivateInfo.h"
#include "FortTeamHealthInfo.generated.h"

class AFortTeamHealthInfo;
class AFortTeamInfo;
class UFortPlayerHealthInfoComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, AFortTeamHealthInfo*, TeamHealthInfo);

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortTeamHealthInfo : public AInfo
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_RepDataReplicated();

	UPROPERTY(Transient, Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerHealthInfoComponent> OwnerHealthComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfo> FortTeamInfo;

	UPROPERTY(ReplicatedUsing=OnRep_RepDataReplicated)
	FPrivateTeamDataArray RepData;

	UPROPERTY(Replicated)
	uint8 TeamNum;

};

