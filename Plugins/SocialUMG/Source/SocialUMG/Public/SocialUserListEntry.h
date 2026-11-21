// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonButtonLegacy.h"
#include "SocialUserListEntry.generated.h"

class UCommonRichTextBlock;
class UMenuAnchor;
class USocialActionMenu;
class USocialNameTextBlock;
class UUserWidget;

UCLASS(Abstract)
class SOCIALUMG_API USocialListEntryBase : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class SOCIALUMG_API USocialListInteractableEntryBase : public USocialListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	UUserWidget* HandleGetMenuContent();

	UPROPERTY(EditAnywhere, Category="SocialListInteractableEntryBase")
	TSubclassOf<USocialActionMenu> ActionMenuClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> MenuAnchor_Actions;

private:
	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsMenuOpen);

};

UCLASS(Abstract)
class SOCIALUMG_API USocialListUserEntryBase : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="SocialListUserEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_RichPresence;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_RichPresence_Hover;

};

