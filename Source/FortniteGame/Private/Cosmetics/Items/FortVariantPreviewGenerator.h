// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "FortVariantPreviewGenerator.generated.h"

class UAthenaItemWrapDefinition;

UCLASS(Abstract, EditInlineNew)
class UFortVariantPreviewGenerator : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UFortWrapVariantPreviewGenerator : public UFortVariantPreviewGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortWrapVariantPreviewGenerator", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag WrapVariantChannelTag;

	UPROPERTY(EditAnywhere, Category="FortWrapVariantPreviewGenerator")
	FFortCosmeticVariantPreview BaseVariantPreview;

	UPROPERTY(EditAnywhere, Category="FortWrapVariantPreviewGenerator")
	int32 NumWrapPreviews;

	UPROPERTY(EditAnywhere, Category="FortWrapVariantPreviewGenerator")
	TArray<TSoftObjectPtr<UAthenaItemWrapDefinition>> PreviewWrapDefinitions;

	UPROPERTY(EditAnywhere, Category="FortWrapVariantPreviewGenerator")
	FString DefaultCustomData;

};

