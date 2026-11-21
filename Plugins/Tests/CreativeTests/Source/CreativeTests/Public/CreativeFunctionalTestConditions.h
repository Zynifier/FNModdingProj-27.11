// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "CreativeFunctionalTestConditions.generated.h"

class AController;
class UCreativeFunctionalTestConditionComponentBase;
class UFortItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreativeFunctionalTestConditionEvent, UCreativeFunctionalTestConditionComponentBase*, Condition);

USTRUCT(BlueprintType)
struct FCreativeFunctionalTest_ItemCountPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Creative|Inventory")
	TObjectPtr<UFortItemDefinition> ItemDef;

	UPROPERTY(EditAnywhere, Category="Creative|Inventory")
	int32 ExpectedCount;

	UPROPERTY(Transient)
	int32 FoundCount;

	UPROPERTY(Transient)
	TMap<FGuid, int32> ItemGuidToCount;

};

UCLASS(BlueprintType, Blueprintable)
class UCreativeFunctionalTestConditionComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void CleanupAfterTest();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="CreativeTest")
	bool ConditionHasBeenSatisfied() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="CreativeTest")
	bool GetTestResult(FString& TestMessage) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeTest")
	void SetConditionSatisfied(bool bValue);

	UFUNCTION(BlueprintNativeEvent)
	void SetupForTest();

	UPROPERTY(BlueprintAssignable)
	FCreativeFunctionalTestConditionEvent OnConditionSatisfiedChange;

private:
	UPROPERTY(Transient)
	bool bConditionSatisifed;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("CreativeTest"), meta=(BlueprintSpawnableComponent))
class UCreativeFunctionalTestConditionComponent_CheckInventory : public UCreativeFunctionalTestConditionComponentBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CreativeTest")
	TArray<FCreativeFunctionalTest_ItemCountPair> ExpectedInventory;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("CreativeTest"), meta=(BlueprintSpawnableComponent))
class UCreativeFunctionalTestConditionComponent_ReceiveOnChannel : public UCreativeFunctionalTestConditionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CreativeTest")
	void SetChannelId(const FGameplayTagContainer& NewChannelIds);

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnReceiveOnChannel(AController* Instigator);

	UPROPERTY(EditAnywhere, Category="CreativeTest", meta=(Categories="Creative.Message.Channel"))
	FGameplayTagContainer ChannelIds;

};

