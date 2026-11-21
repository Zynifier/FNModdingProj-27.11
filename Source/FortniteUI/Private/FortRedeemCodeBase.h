// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortRedeemCodeBase.generated.h"

class UEditableText;
enum class ERedeemCodeFailureReason : uint8;

UENUM(BlueprintType)
enum class ERedeemCodeFailureReason : uint8
{
	InvalidCode = 0,
	// This code is invalid

	CodeAlreadyUsed = 1,
	// This code is already in use

	AlreadyHasAccess = 2,
	// This user has access

	FailedToGetItem = 3,
	Unknown = 4,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRedeemCodeBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="RedeemCodes")
	void OnRedeemFriendCodeComplete(bool bSuccess, ERedeemCodeFailureReason FailureReason);

	UFUNCTION(BlueprintCallable, Category="RedeemCodes")
	void RedeemFriendCode(const FString& FriendCode);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortRedeemCodeBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_FriendCodeEntry;

};

