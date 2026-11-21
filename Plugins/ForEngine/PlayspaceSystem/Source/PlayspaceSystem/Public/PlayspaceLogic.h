// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayspaceLogic.generated.h"

class APlayspace;

UCLASS(BlueprintType)
class PLAYSPACESYSTEM_API APlayspaceLogic : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnRep_MatchStartTime();

	UPROPERTY(Transient)
	TObjectPtr<APlayspace> Playspace;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceLogic")
	bool bAutoStartMatchOnServerStart;

private:
	UFUNCTION()
	void OnRep_bMatchHasEnded();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bMatchHasEnded)
	bool bMatchHasEnded;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MatchStartTime)
	float MatchStartTime;

};

