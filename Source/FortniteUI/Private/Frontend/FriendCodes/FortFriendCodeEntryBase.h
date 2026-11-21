// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/FriendCodes/FortMobileShareButton.h"
#include "Online/FortMcpTypes.h"
#include "FortFriendCodeEntryBase.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UFortFriendCodeEntryBase : public UFortMobileShareButton
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFriendCode FriendCode;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFriendCodeEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> LinkDataTextBox;

	UPROPERTY(BlueprintReadOnly, Category="FortFriendCodeEntryBase")
	FString DebugName;

protected:
	UPROPERTY(EditAnywhere, Category="FortFriendCodeEntryBase")
	int32 LengthOfCode;

	UPROPERTY(EditAnywhere, Category="FortFriendCodeEntryBase")
	FText SharedMessage;

	UPROPERTY(EditAnywhere, Category="FortFriendCodeEntryBase")
	FText SharedMessageNoInvite;

};

