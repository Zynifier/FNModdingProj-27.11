// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortCreativeRichTextStyleSets.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FCreativeRichTextData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeRichTextData")
	TObjectPtr<UDataTable> RichTextStyleSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeRichTextData")
	FText DisplayName;

};

UCLASS()
class UFortCreativeRichTextStyleSets : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeRichTextStyleSets")
	TArray<FCreativeRichTextData> RichTextStylesList;

};

