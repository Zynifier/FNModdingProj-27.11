// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeEntry.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeEntry : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_ObjectiveTitle;

};

