// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "FortSanitizedEditableText.h"
#include "FortFilteredNameEntryWidget.generated.h"

class UCommonButtonBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRenameInput);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTextCommitByEnter);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortFilteredNameEntryWidget : public UFortEditableFilteredCountedTextBox
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnTextCommitByEnter OnTextCommitByEnter;

	UPROPERTY(BlueprintAssignable)
	FOnRenameInput OnRenameInput;

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RenameInputButton;

private:
	UFUNCTION()
	void HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(BlueprintReadOnly, Category="FortFilteredNameEntryWidget", meta=(AllowPrivateAccess))
	TEnumAsByte<ETextCommit::Type> LastTextCommittedType;

};

