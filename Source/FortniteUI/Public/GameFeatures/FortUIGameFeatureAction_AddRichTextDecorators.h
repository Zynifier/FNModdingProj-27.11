// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRichTextDecoratorExtension.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddRichTextDecorators.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Text Decorators"))
class UFortUIGameFeatureAction_AddRichTextDecorators : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortUIGameFeatureAction_AddRichTextDecorators", meta=(DisplayName="Additional Rich Text Decorators"))
	TArray<FFortRichTextDecoratorExtension> AdditionalRichTextDecorators;

};

