// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaCollectionScreenContainerTabButton.h"
#include "FortSidebarCollectionScreenContainerTabButton.generated.h"

class URichTextBlock;
enum class ESocialTagCategory : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarCollectionScreenContainerTabButton : public UAthenaCollectionScreenContainerTabButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnTagCategoryChange(const ESocialTagCategory InTagCategory);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarCollectionScreenContainerTabButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_TabTitle;

};

