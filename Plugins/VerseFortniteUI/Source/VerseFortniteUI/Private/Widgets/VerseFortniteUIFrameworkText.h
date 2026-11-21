// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Widgets/UIFTextBlock.h"
#include "VerseFortniteUIFrameworkText.generated.h"

class APlayerController;

UCLASS(Abstract)
class UVerseFortniteUIFrameworkText_Base : public UUIFrameworkTextBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ExecuteServerTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod);

private:
	UFUNCTION(Server, Reliable)
	void ServerTextCommitted(APlayerController* PlayerController, const FText& NewText);

};

UCLASS()
class UVerseFortniteUIFrameworkEditableText : public UVerseFortniteUIFrameworkText_Base
{
	GENERATED_BODY()

};

UCLASS()
class UVerseFortniteUIFrameworkEditableTextBox : public UVerseFortniteUIFrameworkText_Base
{
	GENERATED_BODY()

};

UCLASS()
class UVerseFortniteUIFrameworkTextBlock : public UUIFrameworkTextBlock
{
	GENERATED_BODY()

};

