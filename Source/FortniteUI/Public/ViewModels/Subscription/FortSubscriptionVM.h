// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMcpProfileCommonCore.h"
#include "ViewModels/FortPerUserViewModel.h"
#include "FortSubscriptionVM.generated.h"

UCLASS(MinimalAPI)
class UFortSubscriptionVM : public UFortPerUserViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateSubscriptionData();

private:
	UPROPERTY(BlueprintReadOnly, Category="FortSubscriptionVM", meta=(AllowPrivateAccess))
	EMcpSubscriptionState SubscriptionState;

	UPROPERTY(BlueprintReadOnly, Category="FortSubscriptionVM", meta=(AllowPrivateAccess))
	bool bIsSubscriptionOwned;

};

