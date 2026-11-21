// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaRespawnTimer.generated.h"

class AFortPlayerControllerZone;
class UCommonTextBlock;
class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaRespawnTimer : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddExtensionWidget(UWidget* Widget);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Add Extension Widget"))
	void AddExtensionWidget_BP(UWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTickDown();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimeEnded();

	UPROPERTY(EditAnywhere, Category="AthenaRespawnTimer", meta=(ClampMin="0.000000"))
	float MinUpdateTime;

	UPROPERTY(EditAnywhere, Category="AthenaRespawnTimer", meta=(ClampMin="0.000000"))
	float CreativeMinUpdateTime;

private:
	UFUNCTION()
	void HandleStartedRespawn(AFortPlayerControllerZone* PlayerController);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Time;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0.000000", DisplayName="Respawn Time"))
	float DesignTime_RespawnTime;
#endif

};

