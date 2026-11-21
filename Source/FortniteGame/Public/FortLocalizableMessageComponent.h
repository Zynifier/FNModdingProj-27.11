// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LocalizableMessage.h"
#include "FortLocalizableMessageComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMessageLocalized);

USTRUCT()
struct FLocalizableProperty
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FLocalizableMessage Message;

	UPROPERTY()
	FName Name;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortLocalizableMessageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void LocalizeAndSetMessage(const FLocalizableMessage& MessageToLocalize, const FText& PropertyToAssignTo);

	UFUNCTION()
	void OnRep_MessageProperties(TArray<FLocalizableProperty> OldMessages);

	UPROPERTY(BlueprintAssignable)
	FOnMessageLocalized OnMessageLocalized;

private:
	UPROPERTY(ReplicatedUsing=OnRep_MessageProperties)
	TArray<FLocalizableProperty> MessageProperties;

};

