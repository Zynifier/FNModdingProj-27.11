// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "FortLFGFilterCheckboxEntryWidget.generated.h"

class UFortSidebarCheckboxWidget;
class USocialTagWidget;

UCLASS(meta=(DisableNativeTick))
class UFortLFGFilterCheckboxEntryWidget : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLFGFilterCheckboxEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialTagWidget> SocialTagWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLFGFilterCheckboxEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarCheckboxWidget> Checkbox;

};

