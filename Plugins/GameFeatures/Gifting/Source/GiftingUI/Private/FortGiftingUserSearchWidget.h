// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Types/SlateEnums.h"
#include "FortGiftingUserSearchWidget.generated.h"

class UCommonButtonBase;
class UEditableText;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortGiftingUserSearchWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void FocusEditableText();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchCommit(bool bSearchStringShort);

private:
	UFUNCTION()
	void HandleSearchFriendsTextChanged(const FText& Text);

	UFUNCTION()
	void HandleSearchFriendsTextEntered(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_SearchFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ClearQuery;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SubmitQuery;

};

