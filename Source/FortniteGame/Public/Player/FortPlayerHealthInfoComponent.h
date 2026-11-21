// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortPlayerHealthInfoComponent.generated.h"

class AFortTeamHealthInfo;

UCLASS(Abstract, MinimalAPI)
class UFortPlayerHealthInfoComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnHealthChanged(AFortTeamHealthInfo* TeamHealthInfo);

	UFUNCTION()
	void OnRep_TeamHealthInfoArray();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TeamHealthInfoArray)
	TArray<TWeakObjectPtr<AFortTeamHealthInfo>> TeamHealthInfoArray;

};

