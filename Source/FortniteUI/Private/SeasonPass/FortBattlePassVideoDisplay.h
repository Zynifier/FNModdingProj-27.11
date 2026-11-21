// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonVideoPlayer.h"
#include "Math/MathFwd.h"
#include "FortBattlePassVideoDisplay.generated.h"

class UAthenaSeasonItemDefinition;
class UCommonTextBlock;
class UCurveFloat;
class UFortBattlePassVideoAnnotationWidget;
class UFortItemDefinition;

USTRUCT()
struct FFortBattlePassVideoAnnotation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation")
	float StartTime;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation")
	float EndTime;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation")
	FVector2D ScreenPosition;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation", meta=(ClampMax="359", ClampMin="0"))
	int32 EntryAngle;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float EntryMagnitude;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotation")
	TObjectPtr<UFortItemDefinition> RewardItemDefinition;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassVideoAnnotationWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoAnnotationWidget")
	TObjectPtr<UCurveFloat> IntroOutroCurve;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemSource;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

};

UCLASS()
class UFortBattlePassVideoDisplay : public UCommonVideoPlayer
{
	GENERATED_BODY()

public:
	UFortBattlePassVideoDisplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoDisplay")
	TSubclassOf<UFortBattlePassVideoAnnotationWidget> AnnotationWidgetClass;

	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoDisplay")
	TArray<FFortBattlePassVideoAnnotation> VideoAnnotations;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortBattlePassVideoDisplay")
	TObjectPtr<UAthenaSeasonItemDefinition> PreviewSeason;
#endif

};

