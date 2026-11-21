// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DynamicEntryBox.h"
#include "Math/MathFwd.h"
#include "Slate/WidgetTransform.h"
#include "FortDynamicEntryBox.generated.h"

UENUM(BlueprintType)
enum class EDynamicEntryPatternDirection : uint8
{
	FirstToLast = 0,
	LastToFirst = 1,
};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortDynamicEntryBox : public UDynamicEntryBox
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortniteEntryLayout", meta=(ClampMin="0"))
	int32 MaximumEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortniteEntryLayout")
	EDynamicEntryPatternDirection PatternDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortniteEntryLayout")
	TArray<float> RenderOpacityPattern;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortniteEntryLayout")
	TArray<FWidgetTransform> RenderTransformPattern;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortniteEntryLayout")
	TArray<FVector2D> RenderTransformPivotPattern;

};

