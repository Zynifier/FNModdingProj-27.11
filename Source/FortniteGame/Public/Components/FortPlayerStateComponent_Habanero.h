// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortPlayerStateComponent_Habanero.generated.h"

USTRUCT(BlueprintType)
struct FRankedProgressReplicatedData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RankedProgressReplicatedData")
	FString RankType;

	UPROPERTY(BlueprintReadOnly, Category="RankedProgressReplicatedData")
	int32 Rank;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_Habanero : public UFortPlayerStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FRankedProgressReplicatedData& GetRankedProgress() const;

private:
	UFUNCTION()
	void OnRep_RankedProgress();

	UFUNCTION(Server, Reliable)
	void Server_SetRankedProgress(const FString& InRankedType, const int32 InRank);

	UPROPERTY(ReplicatedUsing=OnRep_RankedProgress)
	FRankedProgressReplicatedData RankedProgress;

};

