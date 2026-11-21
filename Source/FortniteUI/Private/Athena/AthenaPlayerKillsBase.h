// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPlayerKillsBase.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class UObject;
class UTextBlock;

UCLASS(meta=(DisableNativeTick))
class UAthenaPlayerKillsBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetKillsSourcePlayerController(AFortPlayerControllerAthena* InPlayerController);

	UFUNCTION(BlueprintCallable)
	void SetKillsSourcePlayerState(AFortPlayerStateAthena* InPlayerState);

protected:
	UFUNCTION()
	void HandlePlayerViewTargetChanged();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerKillsBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> KillsText;

	UPROPERTY(Transient)
	TObjectPtr<UObject> KillsSource;

	UPROPERTY(Transient)
	bool bCustomKillSource;

};

