// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonRichTextBlock.h"
#include "Math/MathFwd.h"
#include "FortRichTextBlockKeybind.generated.h"

class UFortKeybindWidget;

UCLASS()
class UFortRichTextBlockKeybind : public UCommonRichTextBlock
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Appearance")
	TSubclassOf<UFortKeybindWidget> KeybindWidgetClass;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D DesiredKeybindWidgetSize;

};

