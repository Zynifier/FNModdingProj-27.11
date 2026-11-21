// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "FortCreativeBossInfo.generated.h"

class AFortPlayerState;
class AFortPlayerStateAthena;
class UCommonTextBlock;
class UCreativePlayerHealthInfoComponent;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeBossInfo : public UMinigameWidgetBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleHitPointsChanged(AFortPlayerState* PlayerState, float Health, float HealthMax, float Shield, float ShieldMax);

	UFUNCTION()
	void OnBossPlayerStateChanged(AFortPlayerStateAthena* PlayerState, UCreativePlayerHealthInfoComponent* HealthInfoComponent);

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeBossInfo", meta=(AllowPrivateAccess="true"))
	bool bShowHealthbarIfLocalPlayerIsBoss;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeBossInfo", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeBossInfo", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HealthBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeBossInfo", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ShieldBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeBossInfo", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DBNOBar;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> BossPlayerState;

};

