// Copyright Epic Games, Inc. All Rights Reserved.

#include "Widgets/VerseFortniteUIFrameworkButton.h"
#include "Net/UnrealNetwork.h"

FText UVerseFortniteUIFrameworkButton_Base::GetText() const
{
	return FText();
}

void UVerseFortniteUIFrameworkButton_Base::OnRep_Message()
{
}

void UVerseFortniteUIFrameworkButton_Base::ServerClick_Implementation(APlayerController* PlayerController)
{
}

void UVerseFortniteUIFrameworkButton_Base::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseFortniteUIFrameworkButton_Base, Message);
}
