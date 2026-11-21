// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaAIKillsBase.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class UObject;
class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaAIKillsBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetKillsSourcePlayerController(AFortPlayerControllerAthena* InPlayerController);

	UFUNCTION(BlueprintCallable)
	void SetKillsSourcePlayerState(AFortPlayerStateAthena* InPlayerState);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAIKillsBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> KillsText;

	UPROPERTY(Transient)
	TObjectPtr<UObject> KillsSource;

	UPROPERTY(Transient)
	bool bCustomKillSource;

};

