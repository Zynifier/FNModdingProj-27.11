// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortAutorunLockZone.generated.h"

class UCommonVisibilitySwitcher;

UCLASS()
class UFortAutorunLockZone : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastReleaseAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayAutorunLockZone(bool bIsShown);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsInZoneChanged(bool bNewIsInZone);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReleasedInZone();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AutorunLock")
	bool bIsMoveStickAutorun;

	UPROPERTY(BlueprintReadOnly, Category="FortAutorunLockZone")
	bool bIsInZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AutorunLock")
	bool bIsAutorunLockEnabled;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_ImprovedAutorunLockZone;

};

