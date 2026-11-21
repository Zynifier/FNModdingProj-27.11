// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAnnualRefundTicket.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UFortAnnualRefundTicket : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAnnualRefundTicket(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayLockingAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateAvailableState(const bool bIsAvailable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatePendingState(const bool bIsPending);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AvailableDate;

};

