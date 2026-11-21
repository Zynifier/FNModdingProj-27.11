// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "DiscoverSelectedActivityViewModel.generated.h"

class UFortActivityViewModel;

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Discover Selected Activity View Model"))
class UDiscoverSelectedActivityViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	bool bLoading;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	bool bHasPartyData;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	bool bIsActiveInvite;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	bool bIsPartyPrivate;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	int32 CurrentPartySize;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	FText RichPresenceText;

	UPROPERTY(BlueprintReadOnly, Category="DiscoverSelectedActivityViewModel")
	TObjectPtr<UFortActivityViewModel> ActivityVM;

};

