// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LocalizableMessage.h"
#include "UIFWidget.h"
#include "VerseFortniteUIFrameworkButton.generated.h"

class APlayerController;

UCLASS(Abstract)
class UVerseFortniteUIFrameworkButton_Base : public UUIFrameworkWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="UI Framework")
	FText GetText() const;

private:
	UFUNCTION()
	void OnRep_Message();

	UFUNCTION(Server, Reliable)
	void ServerClick(APlayerController* PlayerController);

	UPROPERTY()
	FText Text;

	UPROPERTY(ReplicatedUsing=OnRep_Message)
	FLocalizableMessage Message;

};

UCLASS()
class UVerseFortniteUIFrameworkButton_Loud : public UVerseFortniteUIFrameworkButton_Base
{
	GENERATED_BODY()

};

UCLASS()
class UVerseFortniteUIFrameworkButton_Quiet : public UVerseFortniteUIFrameworkButton_Base
{
	GENERATED_BODY()

};

UCLASS()
class UVerseFortniteUIFrameworkButton_Regular : public UVerseFortniteUIFrameworkButton_Base
{
	GENERATED_BODY()

};

