// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortSaveLoadoutPopup.generated.h"

class UFortEditableFilteredCountedTextBox;

UENUM(BlueprintType)
enum class EFortLoadoutActionType : uint8
{
	Rename = 0,
	Overwrite = 1,
	SaveNew = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSaveLoadoutPopup : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadoutActionDeclineEvent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadoutActionSaveEvent, FString, NewName);

public:
	UFUNCTION(BlueprintCallable)
	void HandleActionConfirmed(const FString& OptionalNewName);

	UFUNCTION(BlueprintCallable)
	void HandleActionDeclined();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSanitizationReady(const bool bSuccess, const FString& Sanitizedtext);

	UFUNCTION(BlueprintCallable)
	void SanitizeText();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSaveLoadoutPopup", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> Text_EditableLoadoutName;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnLoadoutActionSaveEvent OnActionConfirmedEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnLoadoutActionDeclineEvent OnActionDeclinedEvent;

};

