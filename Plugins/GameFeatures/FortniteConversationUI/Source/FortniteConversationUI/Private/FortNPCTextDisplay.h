// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortNPCTextDisplay.generated.h"

class UCommonRichTextBlock;
class UFortLazyImage;

UCLASS()
class UFortNPCTextDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortNPCTextDisplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnItemNameUpdated(const FString& ItemName);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnTextUpdated();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortNPCTextDisplay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Message;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNPCTextDisplay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_NPCImage;

};

