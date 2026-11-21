// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortRankedViewModel.generated.h"

class UFortSocialUser;

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Ranked View Model"))
class UFortRankedViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSocialUserAsLocalUser();

private:
	UPROPERTY(BlueprintReadWrite, Category="Discover Surface", meta=(AllowPrivateAccess))
	TObjectPtr<UFortSocialUser> SocialUser;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	bool bIsIslandRanked;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	bool bIsPlayerRanked;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	FString RankType;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	int32 CurrentRank;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	int32 HighestRank;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	int32 CurrentPlayerPosition;

	UPROPERTY(BlueprintReadOnly, Category="Ranked", meta=(AllowPrivateAccess))
	float Progress;

};

