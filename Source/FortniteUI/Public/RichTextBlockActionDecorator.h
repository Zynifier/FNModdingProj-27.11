// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "RichTextBlockActionDecorator.generated.h"

class UDataTable;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class URichTextBlockActionDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()

public:
	URichTextBlockActionDecorator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URichTextBlock> OwnerWidget;

	UPROPERTY(EditAnywhere, Category="Appearance", meta=(RequiredAssetDataTags="RowStructure=/Script/CommonUILegacy.CommonInputActionData"))
	TObjectPtr<UDataTable> InputActionTable;

};

