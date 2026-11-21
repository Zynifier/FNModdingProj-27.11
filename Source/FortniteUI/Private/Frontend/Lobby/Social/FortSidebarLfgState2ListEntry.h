// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "SocialUserListEntry.h"
#include "FortSidebarLfgState2ListEntry.generated.h"

class UCommonTextBlock;
enum class ELfgState : uint8;

UCLASS(meta=(DisableNativeTick))
class UFortSidebarLfgState2ListEntry : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged(const ELfgState NewLfgState, const ESlateVisibility BodyVisibility, const FText& StateText, const FText& StateButton);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSidebarLfgState2ListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ButtonText;

};

