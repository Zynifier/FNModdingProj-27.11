// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "UObject/NoExportTypes.h"
#include "FortActivityScalingTextBlock.generated.h"

class UFortActivityScaleFontList;

USTRUCT(BlueprintType)
struct FFortActivityScaleFontData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortActivityScaleFontData", meta=(ClampMin="1"))
	int32 CharacterCountStart;

	UPROPERTY(EditAnywhere, Category="FortActivityScaleFontData", meta=(ClampMin="1"))
	int32 FontSize;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortActivityScaleFontList : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActivityScaleFontList")
	TArray<FFortActivityScaleFontData> ScaleData;

};

UCLASS(PrioritizeCategories=("Content"), meta=(DisableNativeTick))
class UFortActivityScalingTextBlock : public UCommonTextBlock
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CommonText", meta=(AllowPrivateAccess="TRUE", ExposeOnSpawn="TRUE"))
	TSubclassOf<UFortActivityScaleFontList> Scaling;

};

