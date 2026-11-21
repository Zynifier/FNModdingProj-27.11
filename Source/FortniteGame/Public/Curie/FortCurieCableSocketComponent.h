// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ShapeComponent.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortCurieCableSocketComponent.generated.h"

class AActor;
class UFortCurieCableSocketComponent;

USTRUCT(BlueprintType)
struct FFortCurieCableSocketIdentifier
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCurieCableSocketIdentifier", meta=(AllowPrivateAccess, Categories="Curie.Socket"))
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCurieCableSocketIdentifier", meta=(AllowPrivateAccess, ClampMin="0", UIMin="0"))
	int32 Index;

};

USTRUCT()
struct FFortCurieCableSocketConnection
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Category="FortCurieCableSocketConnection")
	TObjectPtr<AActor> ConnectedActor;

	UPROPERTY(EditInstanceOnly, Category="FortCurieCableSocketConnection")
	FFortCurieCableSocketIdentifier ConnectedSocketIdentifier;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCurieCableSocketComponent> ConnectedSocketComponent;

};

USTRUCT()
struct FFortCurieCableSocket
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCurieCableSocket")
	FFortCurieCableSocketIdentifier SocketIdentifier;

	UPROPERTY(EditAnywhere, Category="FortCurieCableSocket")
	FVector Location;

	UPROPERTY(EditInstanceOnly, Category="FortCurieCableSocket")
	FFortCurieCableSocketConnection SocketConnection;

	UPROPERTY(EditAnywhere, Category="FortCurieCableSocket")
	uint8 bAutoSendSignalOnElementAttachment : 1;

	UPROPERTY(EditAnywhere, Category="FortCurieCableSocket")
	uint8 bAutoSendSignalOnElementDetachment : 1;

	UPROPERTY(EditAnywhere, Category="FortCurieCableSocket")
	uint8 bAutoRouteToCurieComponentOnReceive : 1;

	UPROPERTY(Transient)
	TMap<FGameplayTag, float> ReceivedElementToMagnitudeMap;

};

UCLASS(MinimalAPI, HideCategories=("Navigation", "Physics", "Collision", "Lighting", "VirtualTexture", "Tags", "Cooking", "HLOD", "Mobile", "AssetUserData", "Object", "LOD", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Trigger", "VirtualTexture"), meta=(BlueprintSpawnableComponent))
class UFortCurieCableSocketComponent : public UShapeComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCurieCableSignalReceived, const FFortCurieCableSocketIdentifier&, SocketIdentifier, const FGameplayTag&, ElementTag, float, Magnitude);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool Connect(FFortCurieCableSocketIdentifier SourceSocketIdentifier, AActor* DestinationActor, FFortCurieCableSocketIdentifier DestinationSocketIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool Disconnect(FFortCurieCableSocketIdentifier SourceSocketIdentifier);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool GetCableSocketConnection(FFortCurieCableSocketIdentifier SourceSocketIdentifier, AActor*& ConnectedActor, FFortCurieCableSocketIdentifier& ConnectedSocketIdentifier) const;

	UFUNCTION(BlueprintPure)
	void GetCableSocketIdentifiers(TArray<FFortCurieCableSocketIdentifier>& SocketIdentifiers) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FVector GetCableSocketWorldLocation(const FFortCurieCableSocketIdentifier& SocketIdentifier) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FGameplayTagContainer GetOngoingReceivedElementSignals(FFortCurieCableSocketIdentifier SourceSocketIdentifier) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float GetReceivedElementSignalMagnitude(FFortCurieCableSocketIdentifier SocketIdentifier, FGameplayTag ElementTag) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FGameplayTagContainer GetReceivedElementSignals(FFortCurieCableSocketIdentifier SourceSocketIdentifier) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsCableSocketConnected(FFortCurieCableSocketIdentifier SocketIdentifier) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsReceivedElementSignalActive(FFortCurieCableSocketIdentifier SocketIdentifier, FGameplayTag ElementTag) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SendSignal(FFortCurieCableSocketIdentifier SourceSocketIdentifier, FGameplayTag ElementTag, float Magnitude);

	UPROPERTY(BlueprintAssignable)
	FOnCurieCableSignalReceived OnCurieCableSignalReceived;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Shape")
	FColor EditorUnselectedCableSocketColor;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Shape")
	FColor EditorSelectedCableSocketColor;
#endif

	UPROPERTY(EditAnywhere, Category="CurieCableSocket")
	TArray<FFortCurieCableSocket> CableSockets;

	UPROPERTY(EditAnywhere, Category="CurieCableSocket", meta=(ClampMin="1.000000", UIMin="1.000000"))
	float CableSocketRadius;

};

