// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "AthenaLevelEffects.generated.h"

class AFortPlayerStateAthena;
class UCommonBorder;
class UCommonLazyImage;
class UCommonTextBlock;
class UObject;

USTRUCT(BlueprintType)
struct FLevelEffectsData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LevelEffectsData")
	int32 MinPlayerLevel;

	UPROPERTY(EditAnywhere, Category="LevelEffectsData")
	FLinearColor ContentColor;

	UPROPERTY(EditAnywhere, Category="LevelEffectsData")
	FLinearColor OutlineColor;

	UPROPERTY(EditAnywhere, Category="LevelEffectsData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> FlameDisplayObject;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaLevelEffects : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OverridePlayerLevel(int32 PlayerLevel);

	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* InPSA);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Effects Level Changed"))
	void BP_HandleEffectsLevelChanged(int32 EffectsLevel);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Player Level"))
	int32 DesignTime_PlayerLevel;
#endif

	UPROPERTY(EditAnywhere, Category="AthenaLevelEffects")
	TArray<FLevelEffectsData> EffectsData;

	UPROPERTY(EditAnywhere, Category="AthenaLevelEffects")
	TArray<FName> FlameMaterialParameters;

	UPROPERTY(EditAnywhere, Category="AthenaLevelEffects")
	FVector2D FlameMaterialRandomRange;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Container;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LvlDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Level;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Flame;

};

