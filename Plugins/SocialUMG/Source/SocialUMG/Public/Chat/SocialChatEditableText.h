// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Styling/SlateTypes.h"
#include "Types/SlateEnums.h"
#include "SocialChatEditableText.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSocialChatTextChanged, const FText&, Text);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSocialChatTextCommitted, const FText&, Text, TEnumAsByte<ETextCommit::Type>, CommitMethod);

UCLASS()
class SOCIALUMG_API USocialChatEditableText : public UWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FEditableTextStyle EditableTextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FTextBlockStyle AutoCompleteStyle;

};

