// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRichTextDecoratorExtension.generated.h"

class URichTextBlockDecorator;
class UUserWidget;

USTRUCT(BlueprintType)
struct FFortRichTextDecoratorExtension
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortRichTextDecoratorExtension")
	TSoftClassPtr<UUserWidget> TargetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortRichTextDecoratorExtension")
	TArray<TSubclassOf<URichTextBlockDecorator>> Decorators;

};

