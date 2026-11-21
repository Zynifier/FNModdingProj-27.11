// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortPassLevelViewModel.generated.h"

class UFortMcpProfileAthena;

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Pass Level View Model"))
class UFortPassLevelViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Category="Discover Surface", meta=(AllowPrivateAccess))
	TObjectPtr<UFortMcpProfileAthena> AthenaProfile;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	FString CurrentChapter;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	FString CurrentSeason;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	int32 NumBattleStars;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	int32 CurrentXP;

	UPROPERTY(BlueprintReadOnly, Category="Pass Level", meta=(AllowPrivateAccess))
	int32 XpToNextLevel;

};

