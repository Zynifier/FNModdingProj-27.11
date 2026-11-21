// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMcpTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortFriendCodeListBase.generated.h"

class UDynamicEntryBox;
class UFortFriendCodeEntryBase;
class URichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortFriendCodeListBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseAndPopDialog();

	UFUNCTION(BlueprintCallable)
	void DescAndURL();

	UFUNCTION(BlueprintCallable)
	void JustDesc();

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortFriendCodeListBase")
	TArray<FFriendCode> BacchusFriendCodes;

	UPROPERTY(EditAnywhere, Category="FortFriendCodeListBase")
	TSubclassOf<UFortFriendCodeEntryBase> FriendCodeEntryClass;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortFriendCodeEntryBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_FriendCodes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> WarningText;

};

